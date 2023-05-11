#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpu.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------
    /// GpuIdx int    The gpu associated with the RF output.
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class GetGpuResult;
    typedef std::shared_ptr<GetGpuResult> GetGpuResultPtr;
    
    
    class GetGpuResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpuResult();

      GetGpuResult(int gpuIdx, int output, const std::string& id);

      GetGpuResult(CommandBasePtr relatedCommand, int gpuIdx, int output, const std::string& id);

      static GetGpuResultPtr create(int gpuIdx, int output, const std::string& id);

      static GetGpuResultPtr create(CommandBasePtr relatedCommand, int gpuIdx, int output, const std::string& id);
      static GetGpuResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** gpuIdx ****
      int gpuIdx() const;
      void setGpuIdx(int gpuIdx);


      // **** output ****
      int output() const;
      void setOutput(int output);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetGpuResult);
  }
}

