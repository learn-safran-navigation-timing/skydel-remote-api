
#include "GetUdreiForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetUdreiForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetUdreiForEachSVResult::CmdName = "GetUdreiForEachSVResult";
    const char* const GetUdreiForEachSVResult::Documentation = "Result of GetUdreiForEachSV.\n"
      "\n"
      "Name   Type      Description\n"
      "------ --------- --------------------------------------------------------------------------------------------------------------------------\n"
      "System string    \"GPS\" or \"SBAS\".\n"
      "Udreis array int UDREI value to set for each satellite. Zero based index (index 0 => UDREI for SV ID 1, index 1 => UDREI for SV ID 2, etc).";
    const char* const GetUdreiForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetUdreiForEachSVResult);


    GetUdreiForEachSVResult::GetUdreiForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetUdreiForEachSVResult::GetUdreiForEachSVResult(const std::string& system, const std::vector<int>& udreis)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setUdreis(udreis);
    }

    GetUdreiForEachSVResult::GetUdreiForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& udreis)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetUdreiForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Udreis"}; 
      return names; 
    }


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
