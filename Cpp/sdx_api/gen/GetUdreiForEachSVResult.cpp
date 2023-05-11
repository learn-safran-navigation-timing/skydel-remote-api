
#include "gen/GetUdreiForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetUdreiForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetUdreiForEachSVResult::CmdName = "GetUdreiForEachSVResult";
    const char* const GetUdreiForEachSVResult::Documentation = "Result of GetUdreiForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetUdreiForEachSVResult);


    GetUdreiForEachSVResult::GetUdreiForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetUdreiForEachSVResult::GetUdreiForEachSVResult(const std::string& system, const std::vector<int>& udreis)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setUdreis(udreis);
    }

    GetUdreiForEachSVResult::GetUdreiForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& udreis)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setUdreis(udreis);
    }


    GetUdreiForEachSVResultPtr GetUdreiForEachSVResult::create(const std::string& system, const std::vector<int>& udreis)
    {
      return std::make_shared<GetUdreiForEachSVResult>(system, udreis);
    }

    GetUdreiForEachSVResultPtr GetUdreiForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& udreis)
    {
      return std::make_shared<GetUdreiForEachSVResult>(relatedCommand, system, udreis);
    }

    GetUdreiForEachSVResultPtr GetUdreiForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetUdreiForEachSVResult>(ptr);
    }

    bool GetUdreiForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<int>>::is_valid(m_values["Udreis"])
        ;

    }

    std::string GetUdreiForEachSVResult::documentation() const { return Documentation; }


    std::string GetUdreiForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetUdreiForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetUdreiForEachSVResult::udreis() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Udreis"]);
    }

    void GetUdreiForEachSVResult::setUdreis(const std::vector<int>& udreis)
    {
      m_values.AddMember("Udreis", parse_json<std::vector<int>>::format(udreis, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
