#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the ephemeris reference time for the specified constellation.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// SvId        int             The satellite's SV ID.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetEphemerisReferenceTimeForSV;
    typedef std::shared_ptr<GetEphemerisReferenceTimeForSV> GetEphemerisReferenceTimeForSVPtr;
    
    
    class GetEphemerisReferenceTimeForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetEphemerisReferenceTimeForSV();

      GetEphemerisReferenceTimeForSV(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetEphemerisReferenceTimeForSVPtr create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetEphemerisReferenceTimeForSVPtr dynamicCast(CommandBasePtr ptr);
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


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

