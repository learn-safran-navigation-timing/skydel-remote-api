#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the IQ file to playback on the specified target and output. Skydel tries to keep the sampling rate as low as possible. File may be upsampled if it doesn't match with the supported sampling rates.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------
    /// Output int    Output index (zero based)
    /// Id     string Target identifier
    ///

    class GetModulationTargetIQPlayback;
    typedef std::shared_ptr<GetModulationTargetIQPlayback> GetModulationTargetIQPlaybackPtr;
    
    
    class GetModulationTargetIQPlayback : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetModulationTargetIQPlayback();

      GetModulationTargetIQPlayback(int output, const std::string& id);

      static GetModulationTargetIQPlaybackPtr create(int output, const std::string& id);
      static GetModulationTargetIQPlaybackPtr dynamicCast(CommandBasePtr ptr);
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

