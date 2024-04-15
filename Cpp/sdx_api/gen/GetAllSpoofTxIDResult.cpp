
#include "GetAllSpoofTxIDResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSpoofTxIDResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSpoofTxIDResult::CmdName = "GetAllSpoofTxIDResult";
    const char* const GetAllSpoofTxIDResult::Documentation = "Result of GetAllSpoofTxID.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ ------------------------------------\n"
      "Ids  array string ID list of all spoofer transmitters.";
    const char* const GetAllSpoofTxIDResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSpoofTxIDResult);


    GetAllSpoofTxIDResult::GetAllSpoofTxIDResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllSpoofTxIDResult::GetAllSpoofTxIDResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetAllSpoofTxIDResult::GetAllSpoofTxIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIds(ids);
    }


    GetAllSpoofTxIDResultPtr GetAllSpoofTxIDResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllSpoofTxIDResult>(ids);
    }

    GetAllSpoofTxIDResultPtr GetAllSpoofTxIDResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllSpoofTxIDResult>(relatedCommand, ids);
    }

    GetAllSpoofTxIDResultPtr GetAllSpoofTxIDResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSpoofTxIDResult>(ptr);
    }

    bool GetAllSpoofTxIDResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllSpoofTxIDResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllSpoofTxIDResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


    std::vector<std::string> GetAllSpoofTxIDResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllSpoofTxIDResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
