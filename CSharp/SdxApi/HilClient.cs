using System;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Text;

namespace Sdx
{
public class HilClient
{
  enum MessageId
  {
    PushEcef,
    Hello,
    Bye,
    VehicleInfo,
    PushEcefNed
  };

  public bool IsVerbose {get; set;}
  public bool IsConnected {get; private set;}

  private UdpClient m_udpClient;
  byte[] m_receiveData;

  public HilClient() 
  {
    IsConnected = false;
    m_udpClient = new UdpClient();
  }

  public void Connect(string ip, int port)
  {
    m_udpClient.Connect(ip, port);
    IsConnected = true;

    //Send Hello
    byte[] message = {(byte)MessageId.Hello};
    m_udpClient.Send(message, 1);
  }

  public void PushEcef(long elpasedTime, Ecef ecef, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");
    
    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream);
    bw.Write((byte)MessageId.PushEcef);
    bw.Write(elpasedTime);
    bw.Write(ecef.X);
    bw.Write(ecef.Y);
    bw.Write(ecef.Z);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcefNed(long elpasedTime, Ecef ecef, Attitude attitude, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream, Encoding.ASCII);
    bw.Write((byte)MessageId.PushEcefNed);
    bw.Write(elpasedTime);
    bw.Write(ecef.X);
    bw.Write(ecef.Y);
    bw.Write(ecef.Z);
    bw.Write(attitude.Yaw);
    bw.Write(attitude.Pitch);
    bw.Write(attitude.Roll);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public bool HasRecvVehicleInfo(int timeout, bool errorAtTimeout = true)
  {
   if(m_udpClient.Client.Poll(timeout*1000, SelectMode.SelectRead))
   {
     if(!m_udpClient.Client.Connected)
     {
       throw new Exception("Error while receiving vehicle info");
     }
     
     return true;
   }
    
   if(errorAtTimeout)
    throw new Exception("Failed to receive vehicle info. Is simulation running and beginVehicleInfo() called before start?");

    return false;
  }

  public void ClearVehicleInfo()
  {
    while(HasRecvVehicleInfo(0, false))
    {
      ReceiveMessage();
    }
  }

  public bool RecvLastVehicleInfo(ref VehicleInfo simStats)
  {
    // Client expects LastVehicleInfo to be blocking. We block for 10s max.
    if(HasRecvVehicleInfo(10000))
    {
      do
      {
        ReceiveMessage();
      }while(HasRecvVehicleInfo(0, false));

      return RecvVehicleInfo(ref simStats);
    }
    return false;
  }

  public bool RecvNextVehicleInfo(ref VehicleInfo simStats)
  {
    if(HasRecvVehicleInfo(200))
    {
      ReceiveMessage();
      return RecvVehicleInfo(ref simStats);
    }
    return false;
  }

  private bool RecvVehicleInfo(ref VehicleInfo simStats)
  {
    if ((MessageId)m_receiveData[0] == MessageId.VehicleInfo)
    {
      MemoryStream memStream = new MemoryStream(m_receiveData);
      BinaryReader binReader = new BinaryReader(memStream);

      binReader.ReadByte();
      simStats.ElapsedTime = binReader.ReadInt64();
      Ecef position = new Ecef(
        binReader.ReadDouble(), 
        binReader.ReadDouble(), 
        binReader.ReadDouble());
      simStats.Position = position;
      Attitude attitude = new Attitude(
        binReader.ReadDouble(),
        binReader.ReadDouble(),
        binReader.ReadDouble());
      simStats.Attitude = attitude;
      simStats.Speed = binReader.ReadDouble();
      simStats.Heading = binReader.ReadDouble();
      simStats.Odometer = binReader.ReadDouble();

      return true;
    }

    return false;
  }

  private void ReceiveMessage()
  {
    IPEndPoint endPoint = new IPEndPoint(IPAddress.Any, 0);
    m_receiveData = m_udpClient.Receive(ref endPoint);

    if (m_receiveData.Length == 0)
    {
      throw new Exception("Error while receiving udp message");
    }
  }

  public void Disconnect()
  {
    if (!IsConnected)
      return;

    //Send Bye
    byte[] message = { (byte)MessageId.Bye };
    m_udpClient.Send(message, 1);

    m_udpClient.Client.Shutdown(SocketShutdown.Both);
    m_udpClient.Client.Close();
    m_udpClient.Close();
    IsConnected = false;
  }
}
} // namespace Bb
