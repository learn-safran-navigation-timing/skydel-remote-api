
#include "gen/GetIonoGridMaskAllResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridMaskAllResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridMaskAllResult::CmdName = "GetIonoGridMaskAllResult";
    const char* const GetIonoGridMaskAllResult::Documentation = "Result of GetIonoGridMaskAll.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIonoGridMaskAllResult);


    GetIonoGridMaskAllResult::GetIonoGridMaskAllResult()
      : CommandResult(CmdName)
    {}

    GetIonoGridMaskAllResult::GetIonoGridMaskAllResult(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
      : CommandResult(CmdName)
    {

      setServiceProvider(serviceProvider);
      setGrid(grid);
    }

    GetIonoGridMaskAllResult::GetIonoGridMaskAllResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
      : CommandResult(CmdName, relatedCommand)
    {

      setServiceProvider(serviceProvider);
      setGrid(grid);
    }


    GetIonoGridMaskAllResultPtr GetIonoGridMaskAllResult::create(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
    {
      return std::make_shared<GetIonoGridMaskAllResult>(serviceProvider, grid);
    }

    GetIonoGridMaskAllResultPtr GetIonoGridMaskAllResult::create(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
    {
      return std::make_shared<GetIonoGridMaskAllResult>(relatedCommand, serviceProvider, grid);
    }

    GetIonoGridMaskAllResultPtr GetIonoGridMaskAllResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridMaskAllResult>(ptr);
    }

    bool GetIonoGridMaskAllResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::vector<std::vector<bool>>>::is_valid(m_values["Grid"])
        ;

    }

    std::string GetIonoGridMaskAllResult::documentation() const { return Documentation; }


    std::string GetIonoGridMaskAllResult::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridMaskAllResult::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::vector<bool>> GetIonoGridMaskAllResult::grid() const
    {
      return parse_json<std::vector<std::vector<bool>>>::parse(m_values["Grid"]);
    }

    void GetIonoGridMaskAllResult::setGrid(const std::vector<std::vector<bool>>& grid)
    {
      m_values.AddMember("Grid", parse_json<std::vector<std::vector<bool>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
