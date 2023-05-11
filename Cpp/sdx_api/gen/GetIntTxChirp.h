#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get informations about the Chirp signal of the transmitter.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string Chirp unique identifier.
    ///

    class GetIntTxChirp;
    typedef std::shared_ptr<GetIntTxChirp> GetIntTxChirpPtr;
    
    
    class GetIntTxChirp : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxChirp();

      GetIntTxChirp(const std::string& transmitterId, const std::string& signalId);

      static GetIntTxChirpPtr create(const std::string& transmitterId, const std::string& signalId);
      static GetIntTxChirpPtr dynamicCast(CommandBasePtr ptr);
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

