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
    Hello = 1,
    Bye = 2,
    VehicleInfo = 3,
    PushEcef = 5,
    PushEcefNed = 6,
    PushEcefDynamics = 7,
    PushEcefNedDynamics = 8
  };

  enum DynamicType
  {
    Velocity,
    Acceleration,
    Jerk
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

  public void writeEcef(ref BinaryWriter bw, Ecef ecef)
  {
    bw.Write(ecef.X);
    bw.Write(ecef.Y);
    bw.Write(ecef.Z);
  }

  public void writeEcefNed(ref BinaryWriter bw, Ecef ecef, Attitude attitude)
  {
    writeEcef(ref bw, ecef);
    bw.Write(attitude.Yaw);
    bw.Write(attitude.Pitch);
    bw.Write(attitude.Roll);
  }

  public void PushEcef(double elapsedTime, Ecef position, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream);

    bw.Write((byte)MessageId.PushEcef);
    bw.Write(elapsedTime);
    writeEcef(ref bw, position);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcef(double elapsedTime, Ecef position, Ecef velocity, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream);

    bw.Write((byte)MessageId.PushEcefDynamics);
    bw.Write((byte)DynamicType.Velocity);
    bw.Write(elapsedTime);
    writeEcef(ref bw, position);
    writeEcef(ref bw, velocity);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcef(double elapsedTime, Ecef position, Ecef velocity, Ecef acceleration, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream);

    bw.Write((byte)MessageId.PushEcefDynamics);
    bw.Write((byte)DynamicType.Acceleration);
    bw.Write(elapsedTime);
    writeEcef(ref bw, position);
    writeEcef(ref bw, velocity);
    writeEcef(ref bw, acceleration);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcef(double elapsedTime, Ecef position, Ecef velocity, Ecef acceleration, Ecef jerk, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");
    

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream);

    bw.Write((byte)MessageId.PushEcefDynamics);
    bw.Write((byte)DynamicType.Jerk);
    bw.Write(elapsedTime);
    writeEcef(ref bw, position);
    writeEcef(ref bw, velocity);
    writeEcef(ref bw, acceleration);
    writeEcef(ref bw, jerk);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream, Encoding.ASCII);
    bw.Write((byte)MessageId.PushEcefNed);
    bw.Write(elapsedTime);
    writeEcefNed(ref bw, position, attitude);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, Ecef velocity, Attitude angularVelocity, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream, Encoding.ASCII);
    bw.Write((byte)MessageId.PushEcefNedDynamics);
    bw.Write((byte)DynamicType.Velocity);
    bw.Write(elapsedTime);
    writeEcefNed(ref bw, position, attitude);
    writeEcefNed(ref bw, velocity, angularVelocity);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, Ecef velocity, Attitude angularVelocity, Ecef acceleration, Attitude angularAcceleration, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream, Encoding.ASCII);
    bw.Write((byte)MessageId.PushEcefNedDynamics);
    bw.Write((byte)DynamicType.Acceleration);
    bw.Write(elapsedTime);
    writeEcefNed(ref bw, position, attitude);
    writeEcefNed(ref bw, velocity, angularVelocity);
    writeEcefNed(ref bw, acceleration, angularAcceleration);
    bw.Write(name.Length);
    bw.Write(Encoding.ASCII.GetBytes(name));
    bw.Seek(0, SeekOrigin.Begin);

    BinaryReader br = new BinaryReader(memStream);
    byte[] data = br.ReadBytes((int)memStream.Length);
    m_udpClient.Send(data, data.Length);
  }

  public void PushEcefNed(double elapsedTime, Ecef position, Attitude attitude, Ecef velocity, Attitude angularVelocity, Ecef acceleration, Attitude angularAcceleration, Ecef jerk, Attitude angularJerk, string name = "")
  {
    if (!IsConnected)
      throw new Exception("Cannot push ecef because you are not connected.");

    MemoryStream memStream = new MemoryStream();
    BinaryWriter bw = new BinaryWriter(memStream, Encoding.ASCII);
    bw.Write((byte)MessageId.PushEcefNedDynamics);
    bw.Write((byte)DynamicType.Jerk);
    bw.Write(elapsedTime);
    writeEcefNed(ref bw, position, attitude);
    writeEcefNed(ref bw, velocity, angularVelocity);
    writeEcefNed(ref bw, acceleration, angularAcceleration);
    writeEcefNed(ref bw, jerk, angularJerk);
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
      simStats.ElapsedTime = binReader.ReadUInt64();
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
} // namespace Sdx
