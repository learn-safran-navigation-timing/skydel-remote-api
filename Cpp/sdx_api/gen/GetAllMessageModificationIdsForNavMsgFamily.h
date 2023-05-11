#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all the message modification event's IDs for this navigation message family and SV ID.
    ///
    /// Name         Type   Description
    /// ------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// NavMsgFamily string Navigation message family key, accepted values : "GPS_LNAV", "GPS_CNAV", "GPS_CNAV2", "GPS_MNAV", "GLONASS_NAV", "GALILEO_FNAV", "GALILEO_INAV", "BEIDOU_D1_NAV", "BEIDOU_CNAV1", "BEIDOU_CNAV2", "QZSS_LNAV", "QZSS_SLAS", "NAVIC_NAV" and "SBAS_NAV"
    /// SvId         int    The satellite's SV ID
    ///

    class GetAllMessageModificationIdsForNavMsgFamily;
    typedef std::shared_ptr<GetAllMessageModificationIdsForNavMsgFamily> GetAllMessageModificationIdsForNavMsgFamilyPtr;
    
    
    class GetAllMessageModificationIdsForNavMsgFamily : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllMessageModificationIdsForNavMsgFamily();

      GetAllMessageModificationIdsForNavMsgFamily(const std::string& navMsgFamily, int svId);

      static GetAllMessageModificationIdsForNavMsgFamilyPtr create(const std::string& navMsgFamily, int svId);
      static GetAllMessageModificationIdsForNavMsgFamilyPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** navMsgFamily ****
      std::string navMsgFamily() const;
      void setNavMsgFamily(const std::string& navMsgFamily);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

