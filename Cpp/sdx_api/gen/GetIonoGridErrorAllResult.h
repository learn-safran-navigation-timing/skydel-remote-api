#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
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
      static const char* const TargetId;


      GetIonoGridErrorAllResult();

      GetIonoGridErrorAllResult(const std::vector<std::vector<double>>& grid);

      GetIonoGridErrorAllResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid);

      static GetIonoGridErrorAllResultPtr create(const std::vector<std::vector<double>>& grid);

      static GetIonoGridErrorAllResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid);
      static GetIonoGridErrorAllResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** grid ****
      std::vector<std::vector<double>> grid() const;
      void setGrid(const std::vector<std::vector<double>>& grid);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridErrorAllResult);
  }
}

