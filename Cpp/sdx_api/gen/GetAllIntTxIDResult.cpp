
#include "GetAllIntTxIDResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllIntTxIDResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllIntTxIDResult::CmdName = "GetAllIntTxIDResult";
    const char* const GetAllIntTxIDResult::Documentation = "Result of GetAllIntTxID.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ ------------------------------------------\n"
      "Ids  array string ID list of all interferences transmitters.";
    const char* const GetAllIntTxIDResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllIntTxIDResult);


    GetAllIntTxIDResult::GetAllIntTxIDResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllIntTxIDResult::GetAllIntTxIDResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetAllIntTxIDResult::GetAllIntTxIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIds(ids);
    }


    GetAllIntTxIDResultPtr GetAllIntTxIDResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllIntTxIDResult>(ids);
    }

    GetAllIntTxIDResultPtr GetAllIntTxIDResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllIntTxIDResult>(relatedCommand, ids);
    }

    GetAllIntTxIDResultPtr GetAllIntTxIDResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllIntTxIDResult>(ptr);
    }

    bool GetAllIntTxIDResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllIntTxIDResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllIntTxIDResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


    std::vector<std::string> GetAllIntTxIDResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllIntTxIDResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
