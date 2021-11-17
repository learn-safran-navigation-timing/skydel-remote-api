#pragma once

#include <memory>
#include "command_result.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoGridErrorAll.
    ///
    /// Name Type               Description
    /// ---- ------------------ -----------------------------------------------------------------------
    /// Grid array array double Array containing each band, each band is an array containing the errors
    ///

    class GetIonoGridErrorAllResult;
    typedef std::shared_ptr<GetIonoGridErrorAllResult> GetIonoGridErrorAllResultPtr;
    
    
    class GetIonoGridErrorAllResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoGridErrorAllResult();

      GetIonoGridErrorAllResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid);
  
      static GetIonoGridErrorAllResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid);
      static GetIonoGridErrorAllResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** grid ****
      std::vector<std::vector<double>> grid() const;
      void setGrid(const std::vector<std::vector<double>>& grid);
    };
  }
}

