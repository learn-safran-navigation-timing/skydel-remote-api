
#include "gen/GetIntTxHiddenOnMapResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxHiddenOnMapResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxHiddenOnMapResult::CmdName = "GetIntTxHiddenOnMapResult";
    const char* const GetIntTxHiddenOnMapResult::Documentation = "Result of GetIntTxHiddenOnMap.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxHiddenOnMapResult);


    GetIntTxHiddenOnMapResult::GetIntTxHiddenOnMapResult()
      : CommandResult(CmdName)
    {}

    GetIntTxHiddenOnMapResult::GetIntTxHiddenOnMapResult(bool hiddenOnMap, const std::string& id)
      : CommandResult(CmdName)
    {

      setHiddenOnMap(hiddenOnMap);
      setId(id);
    }

    GetIntTxHiddenOnMapResult::GetIntTxHiddenOnMapResult(CommandBasePtr relatedCommand, bool hiddenOnMap, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setHiddenOnMap(hiddenOnMap);
      setId(id);
    }


    GetIntTxHiddenOnMapResultPtr GetIntTxHiddenOnMapResult::create(bool hiddenOnMap, const std::string& id)
    {
      return std::make_shared<GetIntTxHiddenOnMapResult>(hiddenOnMap, id);
    }

    GetIntTxHiddenOnMapResultPtr GetIntTxHiddenOnMapResult::create(CommandBasePtr relatedCommand, bool hiddenOnMap, const std::string& id)
    {
      return std::make_shared<GetIntTxHiddenOnMapResult>(relatedCommand, hiddenOnMap, id);
    }

    GetIntTxHiddenOnMapResultPtr GetIntTxHiddenOnMapResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxHiddenOnMapResult>(ptr);
    }

    bool GetIntTxHiddenOnMapResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["HiddenOnMap"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxHiddenOnMapResult::documentation() const { return Documentation; }


    bool GetIntTxHiddenOnMapResult::hiddenOnMap() const
    {
      return parse_json<bool>::parse(m_values["HiddenOnMap"]);
    }

    void GetIntTxHiddenOnMapResult::setHiddenOnMap(bool hiddenOnMap)
    {
      m_values.AddMember("HiddenOnMap", parse_json<bool>::format(hiddenOnMap, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxHiddenOnMapResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxHiddenOnMapResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
