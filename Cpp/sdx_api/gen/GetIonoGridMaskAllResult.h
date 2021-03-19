#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoGridMaskAll
    ///
    /// Name            Type             Description
    /// --------------- ---------------- ----------------------------------------------------------------------
    /// ServiceProvider string           The service provider
    /// Grid            array array bool Array containing each band, each band is an array containing the flags
    ///

    class GetIonoGridMaskAllResult;
    typedef std::shared_ptr<GetIonoGridMaskAllResult> GetIonoGridMaskAllResultPtr;
    
    
    class GetIonoGridMaskAllResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoGridMaskAllResult();

      GetIonoGridMaskAllResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid);
  
      static GetIonoGridMaskAllResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid);
      static GetIonoGridMaskAllResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** grid ****
      std::vector<std::vector<bool>> grid() const;
      void setGrid(const std::vector<std::vector<bool>>& grid);
    };
  }
}

