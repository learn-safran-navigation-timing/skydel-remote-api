#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set PULSAR X1 Accuracy Integrity Flag (Accuracy Integrity of X1 Signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- ---------------------------------------------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.
    /// Health      bool            X1 accuracy integrity, false = User Range Error exceeds alarm threshold, true = User Range Error does not exceed alarm threshold.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetPulsarX1AccuracyIntegrityForSV;
    typedef std::shared_ptr<SetPulsarX1AccuracyIntegrityForSV> SetPulsarX1AccuracyIntegrityForSVPtr;
    
    
    class SetPulsarX1AccuracyIntegrityForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPulsarX1AccuracyIntegrityForSV();

      SetPulsarX1AccuracyIntegrityForSV(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static SetPulsarX1AccuracyIntegrityForSVPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static SetPulsarX1AccuracyIntegrityForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

