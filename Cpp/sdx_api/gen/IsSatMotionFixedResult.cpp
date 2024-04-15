
#include "IsSatMotionFixedResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSatMotionFixedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSatMotionFixedResult::CmdName = "IsSatMotionFixedResult";
    const char* const IsSatMotionFixedResult::Documentation = "Result of IsSatMotionFixed.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ --------------------------------------------------------------------------------------------------------------\n"
      "System  string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId    int    The satellite's SV ID.\n"
      "IsFixed bool   If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.";
    const char* const IsSatMotionFixedResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSatMotionFixedResult);


    IsSatMotionFixedResult::IsSatMotionFixedResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsSatMotionFixedResult::IsSatMotionFixedResult(const std::string& system, int svId, bool isFixed)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setIsFixed(isFixed);
    }

    IsSatMotionFixedResult::IsSatMotionFixedResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isFixed)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setIsFixed(isFixed);
    }


    IsSatMotionFixedResultPtr IsSatMotionFixedResult::create(const std::string& system, int svId, bool isFixed)
    {
      return std::make_shared<IsSatMotionFixedResult>(system, svId, isFixed);
    }

    IsSatMotionFixedResultPtr IsSatMotionFixedResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isFixed)
    {
      return std::make_shared<IsSatMotionFixedResult>(relatedCommand, system, svId, isFixed);
    }

    IsSatMotionFixedResultPtr IsSatMotionFixedResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSatMotionFixedResult>(ptr);
    }

    bool IsSatMotionFixedResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["IsFixed"])
        ;

    }

    std::string IsSatMotionFixedResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSatMotionFixedResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "IsFixed"}; 
      return names; 
    }


    std::string IsSatMotionFixedResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void IsSatMotionFixedResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSatMotionFixedResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSatMotionFixedResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool IsSatMotionFixedResult::isFixed() const
    {
      return parse_json<bool>::parse(m_values["IsFixed"]);
    }

    void IsSatMotionFixedResult::setIsFixed(bool isFixed)
    {
      m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
