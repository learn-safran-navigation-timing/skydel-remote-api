#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSVAntennaModelToPrn is deprecated since 21.3. You may use GetSVAntennaModelForSV.
    /// 
    /// Get the antenna model used by the PRN.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    ///

    class GetSVAntennaModelToPrn;
    typedef std::shared_ptr<GetSVAntennaModelToPrn> GetSVAntennaModelToPrnPtr;
    
    
    class GetSVAntennaModelToPrn : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaModelToPrn();

      GetSVAntennaModelToPrn(int prn, const std::string& system);
  
      static GetSVAntennaModelToPrnPtr create(int prn, const std::string& system);
      static GetSVAntennaModelToPrnPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
  }
}

