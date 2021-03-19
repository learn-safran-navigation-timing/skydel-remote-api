#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveAllMultipathForPrn is deprecated since 21.3. You may use RemoveAllMultipathForSV.
    /// 
    /// Disable all multipath for the specified satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------------------
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS and SV ID for QZSS and NavIC.
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)
    ///

    class RemoveAllMultipathForPrn;
    typedef std::shared_ptr<RemoveAllMultipathForPrn> RemoveAllMultipathForPrnPtr;
    
    
    class RemoveAllMultipathForPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveAllMultipathForPrn();

      RemoveAllMultipathForPrn(int prn, const std::string& system, bool reset);
  
      static RemoveAllMultipathForPrnPtr create(int prn, const std::string& system, bool reset);
      static RemoveAllMultipathForPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** reset ****
      bool reset() const;
      void setReset(bool reset);
    };
  }
}

