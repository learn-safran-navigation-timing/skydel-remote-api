
#include "PushSpoofTxTrackEcef.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushSpoofTxTrackEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushSpoofTxTrackEcef::CmdName = "PushSpoofTxTrackEcef";
    const char* const PushSpoofTxTrackEcef::Documentation = "Push an spoofer transmitter track ecef node. Must be called after BeginSpoofTxTrackDefinition and before EndSpoofTxTrackDefinition.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ---------------------------------------\n"
      "Time int    Node Timestamp in miliseconds.\n"
      "X    double X distance from earth-center in meters.\n"
      "Y    double Y distance from earth-center in meters.\n"
      "Z    double Z distance from earth-center in meters.\n"
      "Id   string Transmitter unique identifier.";
    const char* const PushSpoofTxTrackEcef::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(PushSpoofTxTrackEcef);
    REGISTER_COMMAND_TO_FACTORY_IMPL(PushSpoofTxTrackEcef);


    PushSpoofTxTrackEcef::PushSpoofTxTrackEcef()
      : CommandBase(CmdName, TargetId)
    {}

    PushSpoofTxTrackEcef::PushSpoofTxTrackEcef(int time, double x, double y, double z, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setTime(time);
      setX(x);
      setY(y);
      setZ(z);
      setId(id);
    }

    PushSpoofTxTrackEcefPtr PushSpoofTxTrackEcef::create(int time, double x, double y, double z, const std::string& id)
    {
      return std::make_shared<PushSpoofTxTrackEcef>(time, x, y, z, id);
    }

    PushSpoofTxTrackEcefPtr PushSpoofTxTrackEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushSpoofTxTrackEcef>(ptr);
    }

    bool PushSpoofTxTrackEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string PushSpoofTxTrackEcef::documentation() const { return Documentation; }

    const std::vector<std::string>& PushSpoofTxTrackEcef::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Id"}; 
      return names; 
    }


    int PushSpoofTxTrackEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int PushSpoofTxTrackEcef::time() const
    {
      return parse_json<int>::parse(m_values["Time"]);
    }

    void PushSpoofTxTrackEcef::setTime(int time)
    {
      m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushSpoofTxTrackEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushSpoofTxTrackEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushSpoofTxTrackEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushSpoofTxTrackEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string PushSpoofTxTrackEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void PushSpoofTxTrackEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
