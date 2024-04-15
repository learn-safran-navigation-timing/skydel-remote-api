
#include "GetIntTxHiddenOnMap.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxHiddenOnMap
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxHiddenOnMap::CmdName = "GetIntTxHiddenOnMap";
    const char* const GetIntTxHiddenOnMap::Documentation = "Get whether a transmitter should be hidden on the map.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const GetIntTxHiddenOnMap::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxHiddenOnMap);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxHiddenOnMap);


    GetIntTxHiddenOnMap::GetIntTxHiddenOnMap()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxHiddenOnMap::GetIntTxHiddenOnMap(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetIntTxHiddenOnMapPtr GetIntTxHiddenOnMap::create(const std::string& id)
    {
      return std::make_shared<GetIntTxHiddenOnMap>(id);
    }

    GetIntTxHiddenOnMapPtr GetIntTxHiddenOnMap::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxHiddenOnMap>(ptr);
    }

    bool GetIntTxHiddenOnMap::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxHiddenOnMap::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIntTxHiddenOnMap::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetIntTxHiddenOnMap::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxHiddenOnMap::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxHiddenOnMap::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
