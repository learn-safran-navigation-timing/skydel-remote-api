#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the signals for the specified target and output index.
    /// Skydel tries to keep the sampling rate as low as possible,
    /// but it is possible to set constaints with MinRate and MaxRate.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class GetModulationTargetSignals;
    typedef std::shared_ptr<GetModulationTargetSignals> GetModulationTargetSignalsPtr;
    
    
    class GetModulationTargetSignals : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetModulationTargetSignals();

      GetModulationTargetSignals(int output, const std::string& id);

      static GetModulationTargetSignalsPtr create(int output, const std::string& id);
      static GetModulationTargetSignalsPtr dynamicCast(CommandBasePtr ptr);
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

