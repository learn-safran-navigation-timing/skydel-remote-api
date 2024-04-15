#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the GPU associated with a RF output of a modulation target.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------
    /// GpuIdx int    The gpu associated with the RF output.
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class SetGpu;
    typedef std::shared_ptr<SetGpu> SetGpuPtr;
    
    
    class SetGpu : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGpu();

      SetGpu(int gpuIdx, int output, const std::string& id);

      static SetGpuPtr create(int gpuIdx, int output, const std::string& id);
      static SetGpuPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

