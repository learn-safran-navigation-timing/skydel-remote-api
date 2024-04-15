#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set IQ file signal interference.
    ///
    /// Name          Type         Description
    /// ------------- ------------ ---------------------------------------------------
    /// Enabled       bool         Enable (true) or disable (false) the signal
    /// CentralFreq   double       Central frequency (Hz)
    /// Power         double       Power (dB), relative to transmitter reference power
    /// Path          string       Path to the file to play
    /// TransmitterId string       Transmitter unique identifier.
    /// SignalId      string       AWGN unique identifier.
    /// Group         optional int Group, if not using default group.
    ///

    class SetIntTxIqFile;
    typedef std::shared_ptr<SetIntTxIqFile> SetIntTxIqFilePtr;
    
    
    class SetIntTxIqFile : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIntTxIqFile();

      SetIntTxIqFile(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});

      static SetIntTxIqFilePtr create(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const Sdx::optional<int>& group = {});
      static SetIntTxIqFilePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** centralFreq ****
      double centralFreq() const;
      void setCentralFreq(double centralFreq);


      // **** power ****
      double power() const;
      void setPower(double power);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);


      // **** group ****
      Sdx::optional<int> group() const;
      void setGroup(const Sdx::optional<int>& group);
    };
    
  }
}

