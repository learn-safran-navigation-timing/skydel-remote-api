
#include "gen/SetIonoGridErrorAll.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoGridErrorAll
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoGridErrorAll::CmdName = "SetIonoGridErrorAll";
    const char* const SetIonoGridErrorAll::Documentation = "Set Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.";

    REGISTER_COMMAND_FACTORY(SetIonoGridErrorAll);


    SetIonoGridErrorAll::SetIonoGridErrorAll()
      : CommandBase(CmdName)
    {}

    SetIonoGridErrorAll::SetIonoGridErrorAll(const std::vector<std::vector<double>>& grid)
      : CommandBase(CmdName)
    {

      setGrid(grid);
    }

    SetIonoGridErrorAllPtr SetIonoGridErrorAll::create(const std::vector<std::vector<double>>& grid)
    {
      return std::make_shared<SetIonoGridErrorAll>(grid);
    }

    SetIonoGridErrorAllPtr SetIonoGridErrorAll::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoGridErrorAll>(ptr);
    }

    bool SetIonoGridErrorAll::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Grid"])
        ;

    }

    std::string SetIonoGridErrorAll::documentation() const { return Documentation; }


    int SetIonoGridErrorAll::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<double>> SetIonoGridErrorAll::grid() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Grid"]);
    }

    void SetIonoGridErrorAll::setGrid(const std::vector<std::vector<double>>& grid)
    {
      m_values.AddMember("Grid", parse_json<std::vector<std::vector<double>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
