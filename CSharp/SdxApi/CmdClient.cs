using System.Net.Sockets;
using System.IO;
using System;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using Sdx.Cmd;

namespace Sdx
{
public class CmdClient
{
  enum MessageId
  {
    Command = 0,
    Result = 1,
    ApiVersion = 2
  };

  public bool IsVerbose { get; set; }
  public bool IsConnected { get; private set; }

  private TcpClient m_tcpClient;

  public CmdClient()
  {
    IsConnected = false;
  }

  public void Connect(string ip, int port)
  {
    m_tcpClient = new TcpClient(ip, port);
    IsConnected = true;
  }

  public int GetServerApiVersion()
  {
    NetworkStream netStream = m_tcpClient.GetStream();

    BinaryWriter bw = new BinaryWriter(netStream);
    bw.Write((ushort)5);
    bw.Write((byte)MessageId.ApiVersion);
    bw.Write(ApiInfo.COMMANDS_API_VERSION);
    netStream.Flush();

    BinaryReader reader = new BinaryReader(netStream);
    while (true)
    {
      ushort msgSize = reader.ReadUInt16();
      MessageId msgId = (MessageId)reader.ReadByte();
      if (msgId == MessageId.ApiVersion)
      {
        return reader.ReadInt32();
      }
      else //ignore this message
      {
        reader.ReadBytes(msgSize-1);
      }
    }
  }

  public void SendCommand(CommandBase cmd)
  {
    if (!IsConnected)
      throw new Exception("Cannot send command because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream);
    bw.Write((ushort)0);
    bw.Write((byte)MessageId.Command);
    string json = cmd.ToString();
    byte[] jsonArr = System.Text.Encoding.ASCII.GetBytes(json);
    bw.Write(jsonArr);
    bw.Write((byte)0);

    int msgSize = jsonArr.Length + 4;
    bw.Seek(0, SeekOrigin.Begin);
    bw.Write((ushort)(msgSize-2));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes(msgSize);
    NetworkStream netStream = m_tcpClient.GetStream();
    netStream.Write(data, 0, data.Length);
    netStream.Flush();
  }

  public CommandResult WaitCommand(CommandBase cmd)
  {
    BinaryReader netBr = new BinaryReader(m_tcpClient.GetStream());
    while (true)
    {
      ushort msgSize = netBr.ReadUInt16();
      byte[] data = netBr.ReadBytes(msgSize);

      MemoryStream memStream = new MemoryStream(data);
      BinaryReader br = new BinaryReader(memStream);

      MessageId msgId = (MessageId)br.ReadByte();
      if (msgId == MessageId.Result)
      {
        uint msgJsonLength = br.ReadUInt32();
        byte[] msgJsonData = br.ReadBytes((int)msgJsonLength-1);
        string msgJson = System.Text.Encoding.ASCII.GetString(msgJsonData);

        JObject json = JObject.Parse(msgJson);
        string cmdResultName = (string)json[CommandBase.CmdNameKey];
        CommandResult result = (CommandResult)Activator.CreateInstance(Type.GetType("Sdx.Cmd." + cmdResultName), true);
        result.Parse(json);
        if (result == null)
        {
          throw new Exception("Failed to parse " + msgJson);
        }
        if (cmd.Uuid == result.RelatedCommand.Uuid)
          return result;
      }
    }
  }

  public void Disconnect()
  {
    if (!IsConnected)
      return;

    m_tcpClient.GetStream().Close();
    m_tcpClient.Close();
    m_tcpClient = null;
  }
}
} // namespace Bb
