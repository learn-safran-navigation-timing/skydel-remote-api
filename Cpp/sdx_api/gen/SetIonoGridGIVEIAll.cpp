
#include "gen/SetIonoGridGIVEIAll.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoGridGIVEIAll
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoGridGIVEIAll::CmdName = "SetIonoGridGIVEIAll";
    const char* const SetIonoGridGIVEIAll::Documentation = "Set GIVEI in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.";

    REGISTER_COMMAND_FACTORY(SetIonoGridGIVEIAll);


    SetIonoGridGIVEIAll::SetIonoGridGIVEIAll()
      : CommandBase(CmdName)
    {}

    SetIonoGridGIVEIAll::SetIonoGridGIVEIAll(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider)
      : CommandBase(CmdName)
    {

      setGrid(grid);
      setServiceProvider(serviceProvider);
    }

    SetIonoGridGIVEIAllPtr SetIonoGridGIVEIAll::create(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<SetIonoGridGIVEIAll>(grid, serviceProvider);
    }

    SetIonoGridGIVEIAllPtr SetIonoGridGIVEIAll::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoGridGIVEIAll>(ptr);
    }

    bool SetIonoGridGIVEIAll::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<int>>>::is_valid(m_values["Grid"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string SetIonoGridGIVEIAll::documentation() const { return Documentation; }


    int SetIonoGridGIVEIAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<int>> SetIonoGridGIVEIAll::grid() const
    {
      return parse_json<std::vector<std::vector<int>>>::parse(m_values["Grid"]);
    }

    void SetIonoGridGIVEIAll::setGrid(const std::vector<std::vector<int>>& grid)
    {
      m_values.AddMember("Grid", parse_json<std::vector<std::vector<int>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetIonoGridGIVEIAll::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void SetIonoGridGIVEIAll::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
