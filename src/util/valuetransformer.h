#pragma once

#include <memory>
#include <vector>

class SkinContext;
class TransformNode;
class QDomElement;

class ValueTransformer {
  public:
    ~ValueTransformer();

    double transform(double argument) const;
    double transformInverse(double argument) const;

    static std::unique_ptr<ValueTransformer> parseFromXml(const QDomElement& transformElement,
            const SkinContext& context);

  private:
    ValueTransformer(); // only accessible from parseFromXml, not deleted
    void addTransformer(std::unique_ptr<TransformNode> pTransformer);

    std::vector<std::unique_ptr<TransformNode>> m_transformers;
};
