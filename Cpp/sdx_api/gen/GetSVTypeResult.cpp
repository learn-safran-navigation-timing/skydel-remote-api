
#include "gen/GetSVTypeResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVTypeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVTypeResult::CmdName = "GetSVTypeResult";
    const char* const GetSVTypeResult::Documentation = "Result of GetSVType.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSVTypeResult);


    GetSVTypeResult::GetSVTypeResult()
      : CommandResult(CmdName)
    {}

    GetSVTypeResult::GetSVTypeResult(const std::string& system, int svId, const std::string& svType)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setSvType(svType);
    }

    GetSVTypeResult::GetSVTypeResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& svType)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setSvType(svType);
    }


    GetSVTypeResultPtr GetSVTypeResult::create(const std::string& system, int svId, const std::string& svType)
    {
      return std::make_shared<GetSVTypeResult>(system, svId, svType);
    }

    GetSVTypeResultPtr GetSVTypeResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& svType)
    {
      return std::make_shared<GetSVTypeResult>(relatedCommand, system, svId, svType);
    }

    GetSVTypeResultPtr GetSVTypeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVTypeResult>(ptr);
    }

    bool GetSVTypeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["SvType"])
        ;

    }

    std::string GetSVTypeResult::documentation() const { return Documentation; }


    std::string GetSVTypeResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVTypeResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSVTypeResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSVTypeResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSVTypeResult::svType() const
    {
      return parse_json<std::string>::parse(m_values["SvType"]);
    }

    void GetSVTypeResult::setSvType(const std::string& svType)
    {
      m_values.AddMember("SvType", parse_json<std::string>::format(svType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
