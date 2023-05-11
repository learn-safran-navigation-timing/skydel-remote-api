
#include "gen/GetIonoGridGIVEIAll.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridGIVEIAll
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridGIVEIAll::CmdName = "GetIonoGridGIVEIAll";
    const char* const GetIonoGridGIVEIAll::Documentation = "Get GIVEI in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.";

    REGISTER_COMMAND_FACTORY(GetIonoGridGIVEIAll);


    GetIonoGridGIVEIAll::GetIonoGridGIVEIAll(const Sdx::optional<std::string>& serviceProvider)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
    }

    GetIonoGridGIVEIAllPtr GetIonoGridGIVEIAll::create(const Sdx::optional<std::string>& serviceProvider)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetIonoGridGIVEIAll::documentation() const { return Documentation; }


    int GetIonoGridGIVEIAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    Sdx::optional<std::string> GetIonoGridGIVEIAll::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridGIVEIAll::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
