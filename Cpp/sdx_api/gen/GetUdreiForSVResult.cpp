
#include "gen/GetUdreiForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetUdreiForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetUdreiForSVResult::CmdName = "GetUdreiForSVResult";
    const char* const GetUdreiForSVResult::Documentation = "Result of GetUdreiForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetUdreiForSVResult);


    GetUdreiForSVResult::GetUdreiForSVResult()
      : CommandResult(CmdName)
    {}

    GetUdreiForSVResult::GetUdreiForSVResult(const std::string& system, int svId, int udrei)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setUdrei(udrei);
    }

    GetUdreiForSVResult::GetUdreiForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setUdrei(udrei);
    }


    GetUdreiForSVResultPtr GetUdreiForSVResult::create(const std::string& system, int svId, int udrei)
    {
      return std::make_shared<GetUdreiForSVResult>(system, svId, udrei);
    }

    GetUdreiForSVResultPtr GetUdreiForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei)
    {
      return std::make_shared<GetUdreiForSVResult>(relatedCommand, system, svId, udrei);
    }

    GetUdreiForSVResultPtr GetUdreiForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetUdreiForSVResult>(ptr);
    }

    bool GetUdreiForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["Udrei"])
        ;

    }

    std::string GetUdreiForSVResult::documentation() const { return Documentation; }


    std::string GetUdreiForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetUdreiForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetUdreiForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetUdreiForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetUdreiForSVResult::udrei() const
    {
      return parse_json<int>::parse(m_values["Udrei"]);
    }

    void GetUdreiForSVResult::setUdrei(int udrei)
    {
      m_values.AddMember("Udrei", parse_json<int>::format(udrei, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
