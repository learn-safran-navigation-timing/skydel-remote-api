#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetAllMultipathForPrn is deprecated since 21.3. You may use GetAllMultipathForSV.
    /// 
    /// Get all multipath ID for the specified satellite of the constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS and SV ID for QZSS and NavIC.
    ///

    class GetAllMultipathForPrn;
    typedef std::shared_ptr<GetAllMultipathForPrn> GetAllMultipathForPrnPtr;
    
    
    class GetAllMultipathForPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllMultipathForPrn();

      GetAllMultipathForPrn(const std::string& system, int prn);
  
      static GetAllMultipathForPrnPtr create(const std::string& system, int prn);
      static GetAllMultipathForPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

