#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the GPU associated with a RF output of a modulation target.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class GetGpu;
    typedef std::shared_ptr<GetGpu> GetGpuPtr;
    
    
    class GetGpu : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpu();

      GetGpu(int output, const std::string& id);

      static GetGpuPtr create(int output, const std::string& id);
      static GetGpuPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** output ****
      int output() const;
      void setOutput(int output);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

