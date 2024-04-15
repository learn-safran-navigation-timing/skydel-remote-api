
#include "GetIonoGridMaskAllResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridMaskAllResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridMaskAllResult::CmdName = "GetIonoGridMaskAllResult";
    const char* const GetIonoGridMaskAllResult::Documentation = "Result of GetIonoGridMaskAll.\n"
      "\n"
      "Name            Type             Description\n"
      "--------------- ---------------- ----------------------------------------------------------------------\n"
      "ServiceProvider string           The service provider\n"
      "Grid            array array bool Array containing each band, each band is an array containing the flags";
    const char* const GetIonoGridMaskAllResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridMaskAllResult);


    GetIonoGridMaskAllResult::GetIonoGridMaskAllResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIonoGridMaskAllResult::GetIonoGridMaskAllResult(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
      : CommandResult(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setGrid(grid);
    }

    GetIonoGridMaskAllResult::GetIonoGridMaskAllResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetIonoGridMaskAllResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Grid"}; 
      return names; 
    }


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
