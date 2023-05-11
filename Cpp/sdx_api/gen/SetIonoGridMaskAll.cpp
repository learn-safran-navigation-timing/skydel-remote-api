
#include "gen/SetIonoGridMaskAll.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoGridMaskAll
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoGridMaskAll::CmdName = "SetIonoGridMaskAll";
    const char* const SetIonoGridMaskAll::Documentation = "Set Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.";

    REGISTER_COMMAND_FACTORY(SetIonoGridMaskAll);


    SetIonoGridMaskAll::SetIonoGridMaskAll()
      : CommandBase(CmdName)
    {}

    SetIonoGridMaskAll::SetIonoGridMaskAll(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
      setGrid(grid);
    }

    SetIonoGridMaskAllPtr SetIonoGridMaskAll::create(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
    {
      return std::make_shared<SetIonoGridMaskAll>(serviceProvider, grid);
    }

    SetIonoGridMaskAllPtr SetIonoGridMaskAll::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoGridMaskAll>(ptr);
    }

    bool SetIonoGridMaskAll::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::vector<std::vector<bool>>>::is_valid(m_values["Grid"])
        ;

    }

    std::string SetIonoGridMaskAll::documentation() const { return Documentation; }


    int SetIonoGridMaskAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetIonoGridMaskAll::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SetIonoGridMaskAll::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<bool>> SetIonoGridMaskAll::grid() const
    {
      return parse_json<std::vector<std::vector<bool>>>::parse(m_values["Grid"]);
    }

    void SetIonoGridMaskAll::setGrid(const std::vector<std::vector<bool>>& grid)
    {
      m_values.AddMember("Grid", parse_json<std::vector<std::vector<bool>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
