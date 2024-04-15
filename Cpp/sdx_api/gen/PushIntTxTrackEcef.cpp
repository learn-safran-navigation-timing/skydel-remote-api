
#include "PushIntTxTrackEcef.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushIntTxTrackEcef
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushIntTxTrackEcef::CmdName = "PushIntTxTrackEcef";
    const char* const PushIntTxTrackEcef::Documentation = "Push an interference track ecef node. Must be called after BeginIntTxTrackDefinition and before EndIntTxTrackDefinition.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ --------------------------------------\n"
      "Time int    Node Timestamp in miliseconds\n"
      "X    double X distance from earth-center in meters\n"
      "Y    double Y distance from earth-center in meters\n"
      "Z    double Z distance from earth-center in meters\n"
      "Id   string Transmitter unique identifier.";
    const char* const PushIntTxTrackEcef::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(PushIntTxTrackEcef);
    REGISTER_COMMAND_TO_FACTORY_IMPL(PushIntTxTrackEcef);


    PushIntTxTrackEcef::PushIntTxTrackEcef()
      : CommandBase(CmdName, TargetId)
    {}

    PushIntTxTrackEcef::PushIntTxTrackEcef(int time, double x, double y, double z, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setTime(time);
      setX(x);
      setY(y);
      setZ(z);
      setId(id);
    }

    PushIntTxTrackEcefPtr PushIntTxTrackEcef::create(int time, double x, double y, double z, const std::string& id)
    {
      return std::make_shared<PushIntTxTrackEcef>(time, x, y, z, id);
    }

    PushIntTxTrackEcefPtr PushIntTxTrackEcef::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushIntTxTrackEcef>(ptr);
    }

    bool PushIntTxTrackEcef::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Time"])
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string PushIntTxTrackEcef::documentation() const { return Documentation; }

    const std::vector<std::string>& PushIntTxTrackEcef::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Id"}; 
      return names; 
    }


    int PushIntTxTrackEcef::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int PushIntTxTrackEcef::time() const
    {
      return parse_json<int>::parse(m_values["Time"]);
    }

    void PushIntTxTrackEcef::setTime(int time)
    {
      m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcef::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void PushIntTxTrackEcef::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcef::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void PushIntTxTrackEcef::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double PushIntTxTrackEcef::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void PushIntTxTrackEcef::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string PushIntTxTrackEcef::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void PushIntTxTrackEcef::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
