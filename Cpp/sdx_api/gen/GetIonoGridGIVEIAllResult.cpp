
#include "gen/GetIonoGridGIVEIAllResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridGIVEIAllResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridGIVEIAllResult::CmdName = "GetIonoGridGIVEIAllResult";
    const char* const GetIonoGridGIVEIAllResult::Documentation = "Result of GetIonoGridGIVEIAll.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIonoGridGIVEIAllResult);


    GetIonoGridGIVEIAllResult::GetIonoGridGIVEIAllResult()
      : CommandResult(CmdName)
    {}

    GetIonoGridGIVEIAllResult::GetIonoGridGIVEIAllResult(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider)
      : CommandResult(CmdName)
    {

      setGrid(grid);
      setServiceProvider(serviceProvider);
    }

    GetIonoGridGIVEIAllResult::GetIonoGridGIVEIAllResult(CommandBasePtr relatedCommand, const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, relatedCommand)
    {

      setGrid(grid);
      setServiceProvider(serviceProvider);
    }


    GetIonoGridGIVEIAllResultPtr GetIonoGridGIVEIAllResult::create(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetIonoGridGIVEIAllResult>(grid, serviceProvider);
    }

    GetIonoGridGIVEIAllResultPtr GetIonoGridGIVEIAllResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetIonoGridGIVEIAllResult>(relatedCommand, grid, serviceProvider);
    }

    GetIonoGridGIVEIAllResultPtr GetIonoGridGIVEIAllResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridGIVEIAllResult>(ptr);
    }

    bool GetIonoGridGIVEIAllResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<int>>>::is_valid(m_values["Grid"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetIonoGridGIVEIAllResult::documentation() const { return Documentation; }


    std::vector<std::vector<int>> GetIonoGridGIVEIAllResult::grid() const
    {
      return parse_json<std::vector<std::vector<int>>>::parse(m_values["Grid"]);
    }

    void GetIonoGridGIVEIAllResult::setGrid(const std::vector<std::vector<int>>& grid)
    {
      m_values.AddMember("Grid", parse_json<std::vector<std::vector<int>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetIonoGridGIVEIAllResult::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridGIVEIAllResult::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
