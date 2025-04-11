#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetModulationTargetIQPlayback.
    ///
    /// Name   Type         Description
    /// ------ ------------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Output int          Output index (zero based)
    /// Files  array string The paths to the IQ Playback files. Note: only one file is currently supported, the additional files will be ignored.
    /// Gain   int          The gain associated to this output (dB). This value has to be between the radio's minimum and maximum value. A negative value means to use the radio default value.
    /// Id     string       Target identifier
    ///

    class GetModulationTargetIQPlaybackResult;
    typedef std::shared_ptr<GetModulationTargetIQPlaybackResult> GetModulationTargetIQPlaybackResultPtr;
    
    
    class GetModulationTargetIQPlaybackResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetModulationTargetIQPlaybackResult();

      GetModulationTargetIQPlaybackResult(int output, const std::vector<std::string>& files, int gain, const std::string& id);

      GetModulationTargetIQPlaybackResult(CommandBasePtr relatedCommand, int output, const std::vector<std::string>& files, int gain, const std::string& id);

      static GetModulationTargetIQPlaybackResultPtr create(int output, const std::vector<std::string>& files, int gain, const std::string& id);

      static GetModulationTargetIQPlaybackResultPtr create(CommandBasePtr relatedCommand, int output, const std::vector<std::string>& files, int gain, const std::string& id);
      static GetModulationTargetIQPlaybackResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetModulationTargetIQPlaybackResult);
  }
}

