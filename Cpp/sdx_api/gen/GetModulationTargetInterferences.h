#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the specified target and output index to a group of interferences.
    /// An interference transmitter is mapped to a specific RF output by using the same Interference Group Number.
    /// Skydel tries to keep the sampling rate as low as possible,
    /// but it is possible to set constaints with MinRate and MaxRate.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class GetModulationTargetInterferences;
    typedef std::shared_ptr<GetModulationTargetInterferences> GetModulationTargetInterferencesPtr;
    
    
    class GetModulationTargetInterferences : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetModulationTargetInterferences();

      GetModulationTargetInterferences(int output, const std::string& id);

      static GetModulationTargetInterferencesPtr create(int output, const std::string& id);
      static GetModulationTargetInterferencesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

