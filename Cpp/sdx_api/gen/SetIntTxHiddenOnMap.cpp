
#include "gen/SetIntTxHiddenOnMap.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxHiddenOnMap
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxHiddenOnMap::CmdName = "SetIntTxHiddenOnMap";
    const char* const SetIntTxHiddenOnMap::Documentation = "Set whether a transmitter should be hidden on the map.";

    REGISTER_COMMAND_FACTORY(SetIntTxHiddenOnMap);


    SetIntTxHiddenOnMap::SetIntTxHiddenOnMap()
      : CommandBase(CmdName)
    {}

    SetIntTxHiddenOnMap::SetIntTxHiddenOnMap(bool hiddenOnMap, const std::string& id)
      : CommandBase(CmdName)
    {

      setHiddenOnMap(hiddenOnMap);
      setId(id);
    }

    SetIntTxHiddenOnMapPtr SetIntTxHiddenOnMap::create(bool hiddenOnMap, const std::string& id)
    {
      return std::make_shared<SetIntTxHiddenOnMap>(hiddenOnMap, id);
    }

    SetIntTxHiddenOnMapPtr SetIntTxHiddenOnMap::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxHiddenOnMap>(ptr);
    }

    bool SetIntTxHiddenOnMap::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["HiddenOnMap"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxHiddenOnMap::documentation() const { return Documentation; }


    int SetIntTxHiddenOnMap::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxHiddenOnMap::hiddenOnMap() const
    {
      return parse_json<bool>::parse(m_values["HiddenOnMap"]);
    }

    void SetIntTxHiddenOnMap::setHiddenOnMap(bool hiddenOnMap)
    {
      m_values.AddMember("HiddenOnMap", parse_json<bool>::format(hiddenOnMap, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxHiddenOnMap::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxHiddenOnMap::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
