
#include "GetIonoGridGIVEIAll.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridGIVEIAll
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridGIVEIAll::CmdName = "GetIonoGridGIVEIAll";
    const char* const GetIonoGridGIVEIAll::Documentation = "Get GIVEI in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- -------------------------------\n"
      "ServiceProvider optional string The service provider (optional)";
    const char* const GetIonoGridGIVEIAll::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridGIVEIAll);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridGIVEIAll);


    GetIonoGridGIVEIAll::GetIonoGridGIVEIAll(const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
    }

    GetIonoGridGIVEIAllPtr GetIonoGridGIVEIAll::create(const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetIonoGridGIVEIAll>(serviceProvider);
    }

    GetIonoGridGIVEIAllPtr GetIonoGridGIVEIAll::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridGIVEIAll>(ptr);
    }

    bool GetIonoGridGIVEIAll::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetIonoGridGIVEIAll::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridGIVEIAll::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


    int GetIonoGridGIVEIAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::optional<std::string> GetIonoGridGIVEIAll::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridGIVEIAll::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
