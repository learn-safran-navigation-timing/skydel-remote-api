
#include "gen/GetIonoGridMaskAll.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridMaskAll
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridMaskAll::CmdName = "GetIonoGridMaskAll";
    const char* const GetIonoGridMaskAll::Documentation = "Get Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.";

    REGISTER_COMMAND_FACTORY(GetIonoGridMaskAll);


    GetIonoGridMaskAll::GetIonoGridMaskAll()
      : CommandBase(CmdName)
    {}

    GetIonoGridMaskAll::GetIonoGridMaskAll(const std::string& serviceProvider)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
    }

    GetIonoGridMaskAllPtr GetIonoGridMaskAll::create(const std::string& serviceProvider)
    {
      return std::make_shared<GetIonoGridMaskAll>(serviceProvider);
    }

    GetIonoGridMaskAllPtr GetIonoGridMaskAll::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridMaskAll>(ptr);
    }

    bool GetIonoGridMaskAll::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetIonoGridMaskAll::documentation() const { return Documentation; }


    int GetIonoGridMaskAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIonoGridMaskAll::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridMaskAll::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
