#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetPseudorangeRamps is deprecated since 21.3. You may use GetAllPseudorangeRampForSV.
    /// 
    /// Get a list of all the pseudorange ramps IDs for one satellite of a system
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn    int    Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    ///

    class GetPseudorangeRamps;
    typedef std::shared_ptr<GetPseudorangeRamps> GetPseudorangeRampsPtr;
    
    
    class GetPseudorangeRamps : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeRamps();

      GetPseudorangeRamps(const std::string& system, int prn);
  
      static GetPseudorangeRampsPtr create(const std::string& system, int prn);
      static GetPseudorangeRampsPtr dynamicCast(CommandBasePtr ptr);
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

