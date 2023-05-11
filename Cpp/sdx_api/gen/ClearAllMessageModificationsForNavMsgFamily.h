#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clear all message modification events for this navigation message family.
    ///
    /// Name         Type   Description
    /// ------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// NavMsgFamily string Navigation message family key, accepted values : "GPS_LNAV", "GPS_CNAV", "GPS_CNAV2", "GPS_MNAV", "GLONASS_NAV", "GALILEO_FNAV", "GALILEO_INAV", "BEIDOU_D1_NAV", "BEIDOU_CNAV1", "BEIDOU_CNAV2", "QZSS_LNAV", "QZSS_SLAS", "NAVIC_NAV" and "SBAS_NAV"
    ///

    class ClearAllMessageModificationsForNavMsgFamily;
    typedef std::shared_ptr<ClearAllMessageModificationsForNavMsgFamily> ClearAllMessageModificationsForNavMsgFamilyPtr;
    
    
    class ClearAllMessageModificationsForNavMsgFamily : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllMessageModificationsForNavMsgFamily();

      ClearAllMessageModificationsForNavMsgFamily(const std::string& navMsgFamily);

      static ClearAllMessageModificationsForNavMsgFamilyPtr create(const std::string& navMsgFamily);
      static ClearAllMessageModificationsForNavMsgFamilyPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** navMsgFamily ****
      std::string navMsgFamily() const;
      void setNavMsgFamily(const std::string& navMsgFamily);
    };
    
  }
}

