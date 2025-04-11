#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the IQ file to playback on the specified target and output. Skydel tries to keep the sampling rate as low as possible. File may be upsampled if it doesn't match with the supported sampling rates.
    ///
    /// Name   Type         Description
    /// ------ ------------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Output int          Output index (zero based)
    /// Files  array string The paths to the IQ Playback files. Note: only one file is currently supported, the additional files will be ignored.
    /// Gain   int          The gain associated to this output (dB). This value has to be between the radio's minimum and maximum value. A negative value means to use the radio default value.
    /// Id     string       Target identifier
    ///

    class ChangeModulationTargetIQPlayback;
    typedef std::shared_ptr<ChangeModulationTargetIQPlayback> ChangeModulationTargetIQPlaybackPtr;
    
    
    class ChangeModulationTargetIQPlayback : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ChangeModulationTargetIQPlayback();

      ChangeModulationTargetIQPlayback(int output, const std::vector<std::string>& files, int gain, const std::string& id);

      static ChangeModulationTargetIQPlaybackPtr create(int output, const std::vector<std::string>& files, int gain, const std::string& id);
      static ChangeModulationTargetIQPlaybackPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** output ****
      int output() const;
      void setOutput(int output);


      // **** files ****
      std::vector<std::string> files() const;
      void setFiles(const std::vector<std::string>& files);


      // **** gain ****
      int gain() const;
      void setGain(int gain);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

