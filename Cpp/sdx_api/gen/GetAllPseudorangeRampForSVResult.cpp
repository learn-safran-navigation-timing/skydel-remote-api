
#include "gen/GetAllPseudorangeRampForSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllPseudorangeRampForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllPseudorangeRampForSVResult::CmdName = "GetAllPseudorangeRampForSVResult";
    const char* const GetAllPseudorangeRampForSVResult::Documentation = "Result of GetAllPseudorangeRampForSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetAllPseudorangeRampForSVResult);


    GetAllPseudorangeRampForSVResult::GetAllPseudorangeRampForSVResult()
      : CommandResult(CmdName)
    {}

    GetAllPseudorangeRampForSVResult::GetAllPseudorangeRampForSVResult(const std::string& system, int svId, const std::vector<std::string>& ids)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setIds(ids);
    }

    GetAllPseudorangeRampForSVResult::GetAllPseudorangeRampForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& ids)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setIds(ids);
    }


    GetAllPseudorangeRampForSVResultPtr GetAllPseudorangeRampForSVResult::create(const std::string& system, int svId, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllPseudorangeRampForSVResult>(system, svId, ids);
    }

    GetAllPseudorangeRampForSVResultPtr GetAllPseudorangeRampForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllPseudorangeRampForSVResult>(relatedCommand, system, svId, ids);
    }

    GetAllPseudorangeRampForSVResultPtr GetAllPseudorangeRampForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllPseudorangeRampForSVResult>(ptr);
    }

    bool GetAllPseudorangeRampForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllPseudorangeRampForSVResult::documentation() const { return Documentation; }


    std::string GetAllPseudorangeRampForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllPseudorangeRampForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllPseudorangeRampForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllPseudorangeRampForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetAllPseudorangeRampForSVResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllPseudorangeRampForSVResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
