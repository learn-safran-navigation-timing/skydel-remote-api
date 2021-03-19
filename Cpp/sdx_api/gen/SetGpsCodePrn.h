#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsCodePrn is deprecated since 21.3. You may use PrnOfSVID.
    /// 
    /// Set the transmitted PRN code for the specified satellite
    ///
    /// Name           Type Description
    /// -------------- ---- -----------------------------
    /// SatPrn         int  The GPS satellite PRN [1..32]
    /// TransmittedPrn int  The PRN to transmit [1..210]
    ///

    class SetGpsCodePrn;
    typedef std::shared_ptr<SetGpsCodePrn> SetGpsCodePrnPtr;
    
    
    class SetGpsCodePrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsCodePrn();

      SetGpsCodePrn(int satPrn, int transmittedPrn);
  
      static SetGpsCodePrnPtr create(int satPrn, int transmittedPrn);
      static SetGpsCodePrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** satPrn ****
      int satPrn() const;
      void setSatPrn(int satPrn);


      // **** transmittedPrn ****
      int transmittedPrn() const;
      void setTransmittedPrn(int transmittedPrn);
    };
  }
}

