
#include "GetIonoGridErrorAllResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridErrorAllResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridErrorAllResult::CmdName = "GetIonoGridErrorAllResult";
    const char* const GetIonoGridErrorAllResult::Documentation = "Result of GetIonoGridErrorAll.\n"
      "\n"
      "Name Type               Description\n"
      "---- ------------------ -----------------------------------------------------------------------\n"
      "Grid array array double Array containing each band, each band is an array containing the errors";
    const char* const GetIonoGridErrorAllResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridErrorAllResult);


    GetIonoGridErrorAllResult::GetIonoGridErrorAllResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIonoGridErrorAllResult::GetIonoGridErrorAllResult(const std::vector<std::vector<double>>& grid)
      : CommandResult(CmdName, TargetId)
    {

      setGrid(grid);
    }

    GetIonoGridErrorAllResult::GetIonoGridErrorAllResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setGrid(grid);
    }


    GetIonoGridErrorAllResultPtr GetIonoGridErrorAllResult::create(const std::vector<std::vector<double>>& grid)
    {
      return std::make_shared<GetIonoGridErrorAllResult>(grid);
    }

    GetIonoGridErrorAllResultPtr GetIonoGridErrorAllResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid)
    {
      return std::make_shared<GetIonoGridErrorAllResult>(relatedCommand, grid);
    }

    GetIonoGridErrorAllResultPtr GetIonoGridErrorAllResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridErrorAllResult>(ptr);
    }

    bool GetIonoGridErrorAllResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Grid"])
        ;

    }

    std::string GetIonoGridErrorAllResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridErrorAllResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Grid"}; 
      return names; 
    }


    std::vector<std::vector<double>> GetIonoGridErrorAllResult::grid() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Grid"]);
    }

    void GetIonoGridErrorAllResult::setGrid(const std::vector<std::vector<double>>& grid)
    {
      m_values.AddMember("Grid", parse_json<std::vector<std::vector<double>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
