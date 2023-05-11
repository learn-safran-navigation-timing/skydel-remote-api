#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get IQ file signal interference.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string AWGN unique identifier.
    ///

    class GetIntTxIqFile;
    typedef std::shared_ptr<GetIntTxIqFile> GetIntTxIqFilePtr;
    
    
    class GetIntTxIqFile : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxIqFile();

      GetIntTxIqFile(const std::string& transmitterId, const std::string& signalId);

      static GetIntTxIqFilePtr create(const std::string& transmitterId, const std::string& signalId);
      static GetIntTxIqFilePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);
    };
    
  }
}

