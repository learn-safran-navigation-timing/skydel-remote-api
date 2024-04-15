#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes a message modification event for the navigation message family.
    ///
    /// Name         Type   Description
    /// ------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// NavMsgFamily string Navigation message family key, accepted values : "GPS_LNAV", "GPS_CNAV", "GPS_CNAV2", "GPS_MNAV", "GLONASS_NAV", "GALILEO_FNAV", "GALILEO_INAV", "BEIDOU_D1_NAV", "BEIDOU_CNAV1", "BEIDOU_CNAV2", "QZSS_LNAV", "QZSS_SLAS", "NAVIC_NAV" and "SBAS_NAV"
    /// Id           string Unique identifier
    ///

    class RemoveMessageModificationForNavMsgFamily;
    typedef std::shared_ptr<RemoveMessageModificationForNavMsgFamily> RemoveMessageModificationForNavMsgFamilyPtr;
    
    
    class RemoveMessageModificationForNavMsgFamily : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveMessageModificationForNavMsgFamily();

      RemoveMessageModificationForNavMsgFamily(const std::string& navMsgFamily, const std::string& id);

      static RemoveMessageModificationForNavMsgFamilyPtr create(const std::string& navMsgFamily, const std::string& id);
      static RemoveMessageModificationForNavMsgFamilyPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** navMsgFamily ****
      std::string navMsgFamily() const;
      void setNavMsgFamily(const std::string& navMsgFamily);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

