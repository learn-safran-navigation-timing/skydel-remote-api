
#include "gen/IsSatMotionFixedResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSatMotionFixedResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSatMotionFixedResult::CmdName = "IsSatMotionFixedResult";
    const char* const IsSatMotionFixedResult::Documentation = "Result of IsSatMotionFixed.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsSatMotionFixedResult);


    IsSatMotionFixedResult::IsSatMotionFixedResult()
      : CommandResult(CmdName)
    {}

    IsSatMotionFixedResult::IsSatMotionFixedResult(const std::string& system, int svId, bool isFixed)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setIsFixed(isFixed);
    }

    IsSatMotionFixedResult::IsSatMotionFixedResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isFixed)
      : CommandResult(CmdName, relatedCommand)
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
