#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsCodePrn
    ///
    /// Name           Type Description
    /// -------------- ---- -----------------------------
    /// SatPrn         int  The GPS satellite PRN [1..32]
    /// TransmittedPrn int  The PRN to transmit [1..210]
    ///

    class GetGpsCodePrnResult;
    typedef std::shared_ptr<GetGpsCodePrnResult> GetGpsCodePrnResultPtr;
    
    
    class GetGpsCodePrnResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCodePrnResult();

      GetGpsCodePrnResult(CommandBasePtr relatedCommand, int satPrn, int transmittedPrn);
  
      static GetGpsCodePrnResultPtr create(CommandBasePtr relatedCommand, int satPrn, int transmittedPrn);
      static GetGpsCodePrnResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** satPrn ****
      int satPrn() const;
      void setSatPrn(int satPrn);


      // **** transmittedPrn ****
      int transmittedPrn() const;
      void setTransmittedPrn(int transmittedPrn);
    };
  }
}

