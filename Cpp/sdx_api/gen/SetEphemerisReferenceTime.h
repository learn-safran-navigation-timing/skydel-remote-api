#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetEphemerisReferenceTime is deprecated since 21.3. You may use SetEphemerisReferenceTimeForSV.
    /// 
    /// Set the ephemeris reference time for the specified constellation.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// SvId        int             The satellite's SV ID.
    /// Time        datetime        GPS date and time (it is the GPS time expressed in UTC format)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetEphemerisReferenceTime;
    typedef std::shared_ptr<SetEphemerisReferenceTime> SetEphemerisReferenceTimePtr;
    
    
    class SetEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetEphemerisReferenceTime();

      SetEphemerisReferenceTime(const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName = {});

      static SetEphemerisReferenceTimePtr create(const std::string& system, int svId, const Sdx::DateTime& time, const std::optional<std::string>& dataSetName = {});
      static SetEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** time ****
      Sdx::DateTime time() const;
      void setTime(const Sdx::DateTime& time);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

