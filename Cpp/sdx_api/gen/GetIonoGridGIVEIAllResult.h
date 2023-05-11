#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoGridGIVEIAll.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ----------------------------------------------------------------------
    /// Grid            array array int Array containing each band, each band is an array containing the GIVEI
    /// ServiceProvider optional string The service provider (optional)
    ///

    class GetIonoGridGIVEIAllResult;
    typedef std::shared_ptr<GetIonoGridGIVEIAllResult> GetIonoGridGIVEIAllResultPtr;
    
    
    class GetIonoGridGIVEIAllResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoGridGIVEIAllResult();

      GetIonoGridGIVEIAllResult(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider = {});

      GetIonoGridGIVEIAllResult(CommandBasePtr relatedCommand, const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider = {});

      static GetIonoGridGIVEIAllResultPtr create(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider = {});

      static GetIonoGridGIVEIAllResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider = {});
      static GetIonoGridGIVEIAllResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** grid ****
      std::vector<std::vector<int>> grid() const;
      void setGrid(const std::vector<std::vector<int>>& grid);


      // **** serviceProvider ****
      Sdx::optional<std::string> serviceProvider() const;
      void setServiceProvider(const Sdx::optional<std::string>& serviceProvider);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIonoGridGIVEIAllResult);
  }
}

