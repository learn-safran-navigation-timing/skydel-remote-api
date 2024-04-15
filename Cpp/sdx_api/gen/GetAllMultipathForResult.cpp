
#include "GetAllMultipathForResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMultipathForResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMultipathForResult::CmdName = "GetAllMultipathForResult";
    const char* const GetAllMultipathForResult::Documentation = "Result of GetAllMultipathFor(Signal|SV|System) commands.\n"
      "\n"
      "Name Type         Description\n"
      "---- ------------ ------------------------------------------------------\n"
      "Ids  array string IDs of multipaths for the specified argument in getter";
    const char* const GetAllMultipathForResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMultipathForResult);


    GetAllMultipathForResult::GetAllMultipathForResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAllMultipathForResult::GetAllMultipathForResult(const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId)
    {

      setIds(ids);
    }

    GetAllMultipathForResult::GetAllMultipathForResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setIds(ids);
    }


    GetAllMultipathForResultPtr GetAllMultipathForResult::create(const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMultipathForResult>(ids);
    }

    GetAllMultipathForResultPtr GetAllMultipathForResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
    {
      return std::make_shared<GetAllMultipathForResult>(relatedCommand, ids);
    }

    GetAllMultipathForResultPtr GetAllMultipathForResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMultipathForResult>(ptr);
    }

    bool GetAllMultipathForResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
        ;

    }

    std::string GetAllMultipathForResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllMultipathForResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ids"}; 
      return names; 
    }


    std::vector<std::string> GetAllMultipathForResult::ids() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
    }

    void GetAllMultipathForResult::setIds(const std::vector<std::string>& ids)
    {
      m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
