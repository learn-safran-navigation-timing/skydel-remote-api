
#include "SetSatMotionFixed.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSatMotionFixed
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSatMotionFixed::CmdName = "SetSatMotionFixed";
    const char* const SetSatMotionFixed::Documentation = "If IsFixed is set to true, the satellite will not move during the simulation and keep its initial position calculated at the beginning of the simulation.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    The satellite's SV ID.\n"
      "IsFixed bool   If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.";
    const char* const SetSatMotionFixed::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSatMotionFixed);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSatMotionFixed);


    SetSatMotionFixed::SetSatMotionFixed()
      : CommandBase(CmdName, TargetId)
    {}

    SetSatMotionFixed::SetSatMotionFixed(const std::string& system, int svId, bool isFixed)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setIsFixed(isFixed);
    }

    SetSatMotionFixedPtr SetSatMotionFixed::create(const std::string& system, int svId, bool isFixed)
    {
      return std::make_shared<SetSatMotionFixed>(system, svId, isFixed);
    }

    SetSatMotionFixedPtr SetSatMotionFixed::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSatMotionFixed>(ptr);
    }

    bool SetSatMotionFixed::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string SetSatMotionFixed::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSatMotionFixed::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "IsFixed"}; 
      return names; 
    }


    int SetSatMotionFixed::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetSatMotionFixed::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetSatMotionFixed::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetSatMotionFixed::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSatMotionFixed::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetSatMotionFixed::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void SetSatMotionFixed::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
