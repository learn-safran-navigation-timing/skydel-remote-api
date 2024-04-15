#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
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

    class SetEphemerisReferenceTimeForSV;
    typedef std::shared_ptr<SetEphemerisReferenceTimeForSV> SetEphemerisReferenceTimeForSVPtr;
    
    
    class SetEphemerisReferenceTimeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetEphemerisReferenceTimeForSV();

      SetEphemerisReferenceTimeForSV(const std::string& system, int svId, const Sdx::DateTime& time, const Sdx::optional<std::string>& dataSetName = {});

      static SetEphemerisReferenceTimeForSVPtr create(const std::string& system, int svId, const Sdx::DateTime& time, const Sdx::optional<std::string>& dataSetName = {});
      static SetEphemerisReferenceTimeForSVPtr dynamicCast(CommandBasePtr ptr);
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
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

